import { Container, Button } from "react-bootstrap";
import Link from 'next/link';

export default function Waitlist() {
    return <Container className="py-5">
        <center id="im-sorry">
            <h1>You are position {Math.floor(Math.random() * 1000000000).toLocaleString()} in the waitlist.</h1>
            <Link passHref href="/"><Button variant="primary">Go back</Button></Link>
            <p><Link href="/flag">Get the flag for instant access!</Link></p>
        </center>
    </Container>
}