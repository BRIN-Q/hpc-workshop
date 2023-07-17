FROM ruby:2.7

WORKDIR /usr/src/app

COPY Gemfile Gemfile.lock ./

# Update Git for SSH signing
RUN echo "deb http://deb.debian.org/debian bullseye-backports main" >/etc/apt/sources.list.d/bullseye-backports.list
RUN apt update && apt install -y git/bullseye-backports

# Configure GPG signing
RUN apt-get update && apt-get -y install gnupg2

# Configure RubyGems
RUN gem install bundler && bundle install