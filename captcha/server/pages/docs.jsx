import { Container } from "react-bootstrap";
import Link from 'next/link';
import Head from 'next/head';
import docs from '../docs.md';

export default function Docs() {
    return <Container className="py-5">
        <Head><title>1Captcha Documentation</title></Head>
        <p><Link href="/">1Captcha Home</Link></p>
        <div dangerouslySetInnerHTML={{__html: docs}}></div>
    </Container>;
}