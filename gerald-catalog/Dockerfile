FROM node:16

# Copy package files and install canvas dependencies
WORKDIR /usr/src/app
RUN sudo apt-get install build-essential libcairo2-dev libpango1.0-dev libjpeg-dev libgif-dev librsvg2-dev
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
EXPOSE 1337
CMD ["npm", "start"]