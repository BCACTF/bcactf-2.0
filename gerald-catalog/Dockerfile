FROM node:16

# Copy package files and install canvas dependencies
WORKDIR /usr/src/app
RUN apt-get update -y && \
    apt-get install -y build-essential libcairo2-dev libpango1.0-dev libjpeg-dev libgif-dev librsvg2-dev && \
    rm -rf /var/lib/apt/lists/*
COPY server/package*.json ./server/

# Install dependencies
WORKDIR /usr/src/app/server
RUN npm ci

# Copy rest of files
WORKDIR /usr/src/app
COPY . .

# Run "npm build"
WORKDIR /usr/src/app/server
RUN npm run build --if-present

# Expose port and run server
ENV VAPID_PRIVATE_KEY=jbB5Tus4T0EFGgOkTk05E663DzaE7T7EYwf4vNRrR7A
ENV NODE_TLS_REJECT_UNAUTHORIZED=0
EXPOSE 1337
CMD ["npm", "start"]
