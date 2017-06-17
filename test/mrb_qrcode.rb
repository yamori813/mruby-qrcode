##
## QRCode Test
##

assert("QRCode#hello") do
  t = QRCode.new "hello"
  assert_equal("hello", t.hello)
end

assert("QRCode#bye") do
  t = QRCode.new "hello"
  assert_equal("hello bye", t.bye)
end

assert("QRCode.hi") do
  assert_equal("hi!!", QRCode.hi)
end
