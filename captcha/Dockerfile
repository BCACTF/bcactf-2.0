FROM node:16

# Copy package files and install canvas dependencies
WORKDIR /usr/src/app
RUN apt-get update && apt-get install -y build-essential libcairo2-dev libpango1.0-dev libjpeg-dev libgif-dev librsvg2-dev
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
ENV CAPTCHA_CHALLENGE_KEY=0967b1eeeae0ce24b825a1108cdecd94
ENV CAPTCHA_FLAG="bcactf{synthetic_cdo_returns_111l1l1l1l1l1l111l1ll11l1lll1l1l1l1llll1111lll1l1l1l1l}"
EXPOSE 3000
CMD ["npm", "start"]