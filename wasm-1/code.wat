;; This file is not directly seen
;; It is the code that was compiled to wasm
;; It is only here or reference
(module
    (memory $memory (export "memory") 1) ;; 1 page

    (func $compareString (export "compareString") 
        (param $str1 i32) ;; Pointer to null terminating string 1
        (param $str2 i32) ;; pointer to nt string 2
        (result i32) ;; bool true or false 1  or 0 for if they are the same
        
        (local $index i32) ;; increases as it checks each char

        ;; Goes through each character and checks if they are  the same
        ;; If they aren't the same return 0
        ;; If they are the same, continue unless they are a null byte
        (loop $charCheck
            (i32.ne ;; i32.not equal
                (i32.load8_u
                    (i32.add
                        (local.get $index)
                        (local.get $str1)))
                (i32.load8_u
                    (i32.add
                        (local.get $index)
                        (local.get $str2))))
            ;; If they aren't the same, return false
            if
                (return
                    (i32.const 0))
            end

            ;; Otherwise make sure they aren't 0
            (i32.load8_u
                (i32.add
                    (local.get $index)
                    (local.get $str1)))
            if ;; if they are not 0, increase index & continue the loop
             (local.set $index
                (i32.add
                    (local.get $index)
                    (i32.const 1)))
             (br $charCheck)
            end

            ;; otherwise return 1
            (return
                (i32.const 1)))

        (return
            (i32.const 0)))
    
    (func $copyString (export "copyString")
        (param $addr i32)
        (param $newAddr i32)
        
        (local $index i32) ;; Index of the character its copying

        loop $charCopy
            (i32.store8 ;; copy the character
                (i32.add
                    (local.get $index)
                    (local.get $newAddr))
                (i32.load8_u
                    (i32.add
                        (local.get $index)
                        (local.get $addr))))
            (i32.load8_u ;; load up again and make sure it hasn't hit the null byte yet
                (i32.add
                    (local.get $index)
                    (local.get $addr)))
            (i32.eqz)
            if ;; if it has, stop
                return
            end

            (local.set $index
                (i32.add
                    (local.get $index)
                    (i32.const 1)))
            end $charCopy)
    (; Main Program ;)

    ;; Flag is bcactf{w4sm-m4g1c-xRz5} @1016
    ;; Password is WASMP4S5W0RD @1040
    (data (i32.const 1000) "INVALIDPASSWORD\00bcactf{w4sm-m4g1c-xRz5}\00WASMP4S5W0RD\00")
    (func $checkPassword (export "checkPassword")
        (param $addr i32) ;; the address the password was stored in
        (result i32) ;; message to be shown
        
        block $invalid
            (call $compareString
                (local.get $addr)
                (i32.const 1040)) ;; password's address
            br_if $invalid

            (return 
                (i32.const 1000)) ;; invalid password message's address
            end
        (return 
            (i32.const 1016)) ;; flag's address
        )
    )