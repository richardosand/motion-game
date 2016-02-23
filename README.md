# motion-game

motion-game is a cross-platform mobile game engine for RubyMotion. It lets you write mobile games in Ruby for iOS, tvOS and Android.

motion-game is currently in **beta**. Please give it a try and report problems you find to us.

## Features

 * **Use Ruby :-)** motion-game exposes a pure Ruby API to write games for mobile devices. You can write a video game all in Ruby.
 * **100% cross-platform**: motion-game projects are fully cross-platform for iOS, tvOS and Android. One codebase runs everywhere.
 * **Fully-featured**: motion-game has audio, sprites, animations, particles, device sensors / events, scene graph / director, UI widgets, etc.
 * **Solid foundations**: the motion-game API is implemented using popular and stable opensource libraries, such as [cocos2d-x](http://www.cocos2d-x.org/), [box2d](http://box2d.org/), and more. motion-game projects are also based on RubyMotion which offers portable Ruby runtimes for iOS and Android as well as static compilation of Ruby code.
 * **Native compilation**: your Ruby code will be compiled into optimized native code for each platform you target. There is no interpreter and the original Ruby code will not be in the app.
 * **Platform APIs access**: if you need it, you can call the entire set of public iOS, tvOS or Android APIs from Ruby code as well.

## Getting Started

### Installing RubyMotion

[RubyMotion 4.7+](http://rubymotion.com) is required. A starter version can be downloaded for free. You also need to set up your computer for mobile development (iOS and/or tvOS and/or Android). Follow the [Getting Started](http://rubymotion.com/developers) guides after installation.

### Installing motion-game

#### Binaries

motion-game is available as a gem:

```
$ gem install motion-game
```

#### Source

You can build your own copy of motion-game:

```
$ rake build:setup
$ rake build:all
```

### Hello World

```
$ motion create --template=motion-game HelloWorld
$ cd HelloWorld
```

#### iOS

```
$ rake ios:simulator
$ rake ios:device
```

#### tvOS

```
$ rake tvos:simulator
$ rake tvos:device
```

#### Android

```
$ rake android:emulator
$ rake android:device
```

### API reference

The whole framework API is documented. The [API reference](http://www.rubymotion.com/developers/motion-game/_index.html) is available online.

You can also build the API reference locally:

```
$ rake doc
$ open doc/index.html
```

### Samples

The [samples](https://github.com/HipByte/motion-game/tree/master/samples) directory contains sample projects.

## License

Copyright (c) 2015, HipByte (info@hipbyte.com) and contributors. All rights reserved.

Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:

Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
