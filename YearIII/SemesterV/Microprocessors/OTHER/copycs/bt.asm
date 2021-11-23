.model tiny
.386
.code
.startup
mov cx, 0
bts cx, 1
bt cx, 1
btr cx, 1
bt cx, 1
btc cx, 1
.exit
end
