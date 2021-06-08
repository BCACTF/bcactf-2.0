module.exports = {
    webpack(config, options) {
        config.module.rules.push({
            test: /\.md/,
            use: [
                {
                    loader: "html-loader"
                },
                {
                    loader: "markdown-loader"
                }
            ]
        });
        return config;
    },
    future: {
        webpack5: true
    }
};