// My innovative new database, the NoDatabase Database

import { v4 as uuid } from 'uuid';

export interface Gerald {
    name: string;
    caption?: string;
    copyrightClaim?: CopyrightClaim;
}

export interface CopyrightClaim {
    claimant: string;
}

export class DB {
    constructor(private flag: string) {}

    private users: Record<string, {password: string, geraldIDs: string[]}> = {};
    private geralds: Record<string, Gerald> = {};
    
    public createUser(username: string, password: string): boolean {
        if (this.users[username]) return false;
        this.users[username] = {password, geraldIDs: []};

        this.addGerald({
            name: "Gerald",
            caption: "i am dinosaur"
        }, username);
        this.addGerald({
            name: "Also Gerald",
            caption: "my name is gerard"
        }, username);
        this.addGerald({
            name: "Gerald As Well",
            caption: "i love my wife gerardette"
        }, username);
        this.addGerald({
            name: "Flag Gerald",
            caption: this.flag,
            copyrightClaim: {claimant: "Zsofia"}
        }, username);

        return true;
    }

    public authenticate(username: string, password: string): boolean {
        if (!this.users[username]) return false;
        return this.users[username].password === password;
    }

    public getGeralds(username: string): Gerald[] | undefined {
        if (!this.users[username]) return;
        return this.users[username].geraldIDs.map(id => this.geralds[id]);
    }

    public addGerald(gerald: Gerald, username: string): string | undefined {
        if (!this.users[username]) return;
        const id = uuid();
        this.geralds[id] = gerald;
        this.users[username].geraldIDs.push(id);
        console.log(`Added Gerald with id ${id}`);
        return id;
    }

    public getGerald(id: string): Gerald | undefined {
        return this.geralds[id];
    }
}