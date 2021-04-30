interface Page {
    _id: string;
    title?: string;
    content?: string;
    created: Date;
    cspViolations: number;
}