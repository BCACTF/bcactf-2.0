import { Fragment } from "react";
import Link from 'next/link';
import Head from 'next/head';
import { Navbar, Nav, Container, Button, Row, Col } from "react-bootstrap";

export default function Index() {
    return <Fragment>
        <Head>
            <title>1Captcha</title>
        </Head>
        <Navbar bg="primary" variant="dark">
            <Navbar.Brand>1Captcha</Navbar.Brand>
            <Nav className="ml-auto">
                <Link passHref href="/flag"><Nav.Link>Flag</Nav.Link></Link>
                <Link passHref href="/docs"><Nav.Link>API Documentation</Nav.Link></Link>
            </Nav>
        </Navbar>
        <div style={{ backgroundPosition: "center", backgroundSize: "cover", backgroundImage: "linear-gradient(rgba(0, 0, 0, 0.5), rgba(0, 0, 0, 0.5)), url(https://upload.wikimedia.org/wikipedia/commons/5/51/Artificial_Intelligence%2C_AI.jpg)"}}>
            <Container className="py-5 text-white">
                <h1>Introducing 1Captcha</h1>
                <p>Traditional captchas are broken. Try our new lightweight solution today.</p>
                <Link passHref href="/waitlist"><Button variant="dark">Join the waitlist</Button></Link>
            </Container>
        </div>
        <Container className="py-5">
            <Row>
                <Col className="d-flex flex-column justify-content-start align-items-center text-center" xs={4}>
                    <h3>A captcha you <u>will</u> hate</h3>
                    <p>Modern captchas aren't frustrating enough. With 1Captcha, you can protect your site from spam <em>and</em> make your users hate you - all at once.</p>
                </Col>
                <Col className="d-flex flex-column justify-content-start align-items-center text-center" xs={4}>
                    <h3>Embrace the BCACTF</h3>
                    <p>Maybe you remember <em style={{fontFamily: "Times New Roman"}}>that</em> annoying problem from BCACTF 1. Maybe you dislike our choice of Times New Roman as our brand font. Or maybe you just like your <code>1</code>s and <code>l</code>s. Whatever the case, this is the captcha for you.</p>
                </Col>
                <Col className="d-flex flex-column justify-content-start align-items-center text-center" xs={4}>
                    <h3>Tough on bots, tough on humans</h3>
                    <p>Spam is annoying. You know what else is annoying? Humans are. Our CAPTCHA technology not only stops bots, but it also stops humans in their tracks.</p>
                </Col>
            </Row>
        </Container>
        <div className="bg-light">
            <Container className="py-5 d-flex flex-column justify-content-start align-items-center text-center">
                <h3>Blockchain, machine learning, etc.</h3>
                <p><Link passHref href="/waitlist"><Button variant="primary">Join the waitlist</Button></Link></p>
                <p><Link href="/docs"><a>Read the API documentation</a></Link></p>
            </Container>
        </div>
        <Container className="py-3 text-secondary">
            Image credit: <a href="https://commons.wikimedia.org/wiki/File:Artificial_Intelligence,_AI.jpg">mikemacmarketing</a>, <a href="https://creativecommons.org/licenses/by/2.0">CC BY 2.0</a>, via Wikimedia Commons
        </Container>
    </Fragment>
}