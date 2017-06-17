# mruby-qrcode   [![Build Status](https://travis-ci.org/yamori813/mruby-qrcode.svg?branch=master)](https://travis-ci.org/yamori813/mruby-qrcode)
QRCode class
## install by mrbgems
- add conf.gem line to `build_config.rb`

```ruby
MRuby::Build.new do |conf|

    # ... (snip) ...

    conf.gem :github => 'yamori813/mruby-qrcode'
end
```
## example
```ruby
p QRCode.encode(0, 1, [1,2,3,4])
```

## License
under the BSD License:
- see LICENSE file
