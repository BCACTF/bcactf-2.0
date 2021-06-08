import { useState, useRef } from 'react';
import { Button, Col, Container, Overlay, Popover, Row } from 'react-bootstrap';
import Link from 'next/link';

async function load(challenge, answer) {
    let headers = {"Content-Type": "application/json"};
    if (challenge) {
        headers["X-Captcha-Challenge"] = challenge;
    }
    const response = await fetch("/api/challenge", {
        method: "POST",
        headers,
        body: JSON.stringify({answer})
    });
    return await response.json();
}

export default function FlagPage() {
    const [flag, setFlag] = useState("We're currently experiencing high demand for the flag. Please solve the below CAPTCHA to continue.");
    const [data, setData] = useState(null);
    const [challenge, setChallenge] = useState(undefined);
    const [answer, setAnswer] = useState([]);
    const [success, setSuccess] = useState("");
    const target = useRef(null);

    return <Container className="py-5">
        <p>{flag}</p>
        <style jsx>{`
            .captcha-box {
                width: -moz-fit-content;
                width: fit-content;
            }
        `}</style>
        <div className="bg-light border p-3 rounded d-flex justify-content-center align-items-center captcha-box mb-5">
            <a ref={target} href="#" onClick={async e => {
                e.preventDefault();
                if (success === "") {
                    const data = await load(challenge);
                    setData(data);
                    setChallenge(data.challenge);
                    setSuccess("?");
                    setAnswer([false, false, false, false, false, false, false, false, false]);
                }
            }} className="vertical-align-middle mr-2 border-primary bg-white d-inline-block" style={{border: "blue 2px solid", width: "25px", height: "25px", textAlign: "center", lineHeight: "21px"}}>{success}</a>
            <span className="vertical-align-middle">I'm totally not a robot</span>
            <span className="text-secondary ml-2"><small>1Captcha</small></span>
        </div>
        <Overlay show={success === "?"} target={target.current} placement="bottom">
            {props => <Popover {...props}>
                <div style={{width: "200px"}}>
                    {data ? (data.error ? <>
                        <div className="p-3 w-100 text-center text-danger"><strong>Error:</strong> {data.error}</div>
                        <div className="p-2"><Button variant="danger" className="w-100" onClick={async () => {
                            setData(null);
                            const data = await load(undefined);
                            setData(data);
                            setChallenge(data.challenge);
                            setSuccess("?");
                            setAnswer([false, false, false, false, false, false, false, false, false]);
                        }}>Start over</Button></div>
                    </> : <>
                        <div className="font-weight-bold text-white p-2 rounded bg-primary m-2 d-flex align-items-center">
                            <div className="flex-grow-1 pr-1">Select all characters like this:</div>
                            <img src={data.expected} />
                        </div>
                        <Row className="p-1" style={{margin: "0"}}>
                            {data.images.map((image, index) => <Col className="p-1 position-relative" key={index} xs={4}>
                                <a href="#" onClick={e => {
                                    e.preventDefault();
                                    const response = answer.slice();
                                    response[index] = !response[index];
                                    setAnswer(response);
                                }}>
                                    {answer[index] && <div className="position-absolute text-primary" style={{ backgroundColor: "rgba(255, 255, 255, 0.8)", top: "0", left: "0", bottom: "0", right: "0", textAlign: "center", fontSize: "36px", lineHeight: "64px" }}>✓</div>}
                                    <img src={image} className="w-100 h-100 d-inline-block" />
                                </a>
                            </Col>)}
                        </Row>
                        <div className="pt-2 px-2"><Button variant="primary" className="w-100" onClick={async () => {
                            setData(null);
                            const data = await load(challenge, answer);
                            if (data.done) {
                                setSuccess("✓");
                                setChallenge(undefined);
                                setFlag(data.flag || "The problem is misconfigured. Please contact admin.");
                            } else {
                                setData(data);
                                setChallenge(data.challenge);
                                setAnswer([false, false, false, false, false, false, false, false, false]);
                            }
                        }}>Submit</Button></div>
                        <div className="pt-2 px-2 w-100 text-center">Stage {data.stage + 1} of {data.stages}</div>
                        <div className="p-2 text-secondary w-100 text-center">Time limit: {data.time}s</div>
                    </>) : <div className="p-3 w-100 text-center">Loading...</div>}
                </div>
            </Popover>}
        </Overlay>
        <Link href="/docs"><a className="text-secondary">Check out our API documentation!</a></Link>
    </Container>;
}