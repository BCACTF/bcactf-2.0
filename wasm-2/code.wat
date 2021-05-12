

(;
  In short, each char in the flag is xored by its index in the (string * 9) & 63;

  i = 0
  decoded = ""
  while (char = readByte(i)) {
    decoded += char ^ ((i++ * 9) & 63)
  }

  i = 0
  encoded = ""
  while (i < decoded.length) encoded += decoded.charAt(i) ^ ((i++ * 9) & 63)
  
;)


(module
    (memory $memory (export "memory") 1)

    (func $cmp
        (param $v0 i32)
        (param $v1 i32)
        (result i32)

        (local $v2 i32)
       
        (loop $l0
            (i32.ne
                (i32.load8_u
                    (i32.add
                        (local.get $v2)
                        (local.get $v0)))
                (i32.xor
                    (i32.load8_u
                        (i32.add
                            (local.get $v2)
                            (local.get $v1)))
                    (i32.and
                        (i32.mul
                            (local.get $v2)
                            (i32.const 9))
                        (i32.const 0x7F))))
            (i32.ne
                (local.get $v2)
                (i32.const 27))
            i32.and
            if                    
                (return
                    (i32.const 0))
            end
            (i32.load8_u
                (i32.add
                    (i32.sub
                        (local.tee $v2
                            (i32.add
                                (local.get $v2)
                                (i32.const 1)))
                        (i32.const 1))
                    (local.get $v0)))
            i32.eqz
            if
                (return
                    (i32.const 1))
            end
            (br $l0))
        (return
            (i32.const 0)))
    (; Main Program ;)
    (data (i32.const 1000) "\62\6a\73\78\50\4b\4d\48\7c\22\37\4e\1b\44\04\33\62\5d\50\52\19\65\25\7f\2f\3b\17")
    (func $checkFlag (export "checkFlag")
        (param $a i32)
        (result i32)

        (return
            (call $cmp
                (local.get $a)
                (i32.const 1000))))
    )
