from yaml import load
from termcolor import cprint
from pathlib import Path
from typing import Tuple
import warnings
import sys

def check(raw_data) -> "Tuple[list[str], list[str]]":
    data = load(raw_data)
    if not isinstance(data, dict):
        raise Exception("Data must be a dictionary")
    
    errors = []
    warnings = []

    if "name" not in data:
        errors.append('Property "name" is missing')
    elif not isinstance(data["name"], str):
        errors.append('Property "name" must be a string')

    if "category" not in data:
        errors.append('Property "category" is missing')
    elif not isinstance(data["category"], str):
        errors.append('Property "category" must be a string')
    
    if "value" not in data:
        errors.append('Property "value" is missing')
    elif not isinstance(data["value"], int):
        errors.append('Property "value" must be an integer')
    
    if "flag" not in data:
        errors.append('Property "flag" is missing')
    elif isinstance(data["flag"], dict):
        if "file" not in data["flag"]:
            errors.append('Property "flag" must either be a string or a dictionary containing the "file" property')
        elif not isinstance(data["flag"]["file"], str):
            errors.append('Property "flag.file" must be a string')
        elif "ignore_missing" not in data["flag"]:
            path = Path(data["flag"]["file"])
            if not path.exists():
                errors.append('Flag file does not exist. If this is intended, add "ignore_missing: true" to the file in chall.yaml.')
            elif path.is_dir():
                errors.append('Flag file must be a file, not a directory. If this is intended, add "ignore_missing: true" to the file in chall.yaml.')
    elif not isinstance(data["flag"], str):
        errors.append('Property "flag" must either be a string or a dictionary containing the "file" property')
    
    if "description" in data and not isinstance(data["description"], str):
        errors.append('Property "description" must be a string')
    
    if "hints" in data:
        if isinstance(data["hints"], list):
            if any(not isinstance(hint, str) for hint in data["hints"]):
                errors.append('Property "hints" must be a list of strings')
        else:
            errors.append('Property "hints" must be a list of strings')
    
    if "files" in data:
        if isinstance(data["files"], list):
            for i, file in enumerate(data["files"]):
                filename = str(i + 1)
                if isinstance(file, dict):
                    if "src" not in file:
                        errors.append(f"File {filename}: Property \"src\" is missing")
                    elif not isinstance(file["src"], str):
                        errors.append(f"File {filename}: Property \"src\" must be a string")
                    else:
                        filename = f"\"{file['src'].encode('utf8').decode('unicode_escape')}\""
                        if "ignore_missing" not in file and not Path(file["src"]).exists():
                            errors.append(f'File {filename}: Does not exist. If this is intended, add "ignore_missing: true" to the file in chall.yaml.')
                    if "name" in file and not isinstance(file["name"], str):
                        errors.append(f'File {filename}: Property "name" must be a string')
                else:
                    errors.append(f'File {filename}: Must be a dictionary')
        else:
            errors.append('Property "files" must be a list of strings')
    
    if "authors" not in data:
        errors.append('Property "authors" is missing')
    elif isinstance(data["authors"], str):
        errors.append('Property "authors" must be a list of strings, not a string *cough cough anli*')
    elif not isinstance(data["authors"], list):
        errors.append('Property "authors" must be a list of strings')
    elif len(data["authors"]) == 0:
        errors.append('Property "authors" must have at least one element')
    elif any(not isinstance(author, str) for author in data["authors"]):
        errors.append('Property "authors" must be a list of strings')
    
    if "visible" in data and not isinstance(data["visible"], bool):
        errors.append('Property "visible" must be a boolean')
    
    return errors, warnings

if __name__ == "__main__":
    warnings.filterwarnings("ignore")
    cprint("Paste in your chall.yaml file, then send an EOF:", "cyan", attrs=["bold"])
    try:
        raw_data = sys.stdin.read()
        errors, warnings = check(raw_data)
    except Exception as e:
        cprint("Fatal error: ", "red", attrs=["bold"], end="")
        print(e)
        exit(1)

    if len(errors) > 0:
        cprint(f"{len(errors)} error(s) found", "red", attrs=["bold"])
        for error in errors:
            print(error)
    
    if len(warnings) > 0:
        cprint(f"{len(warnings)} warning(s) found", "yellow", attrs=["bold"])
        for warning in warnings:
            print(warning)
    
    if len(errors) > 0:
        exit(1)
    elif len(warnings) == 0:
        cprint("No issues found", "green", attrs=["bold"])
