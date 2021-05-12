program flag_checker_1
    implicit none

    integer(kind = 2) :: i
    character (len = 25) :: input_flag
    integer(kind = 2), dimension(25) :: input_flag_int, compare_flag
    compare_flag(1) = 99
    compare_flag(2) = 101
    compare_flag(3) = 100
    compare_flag(4) = 103
    compare_flag(5) = 121
    compare_flag(6) = 108
    compare_flag(7) = 130
    compare_flag(8) = 110
    compare_flag(9) = 57
    compare_flag(10) = 124
    compare_flag(11) = 127
    compare_flag(12) = 126
    compare_flag(13) = 65
    compare_flag(14) = 92
    compare_flag(15) = 110
    compare_flag(16) = 121
    compare_flag(17) = 70
    compare_flag(18) = 113
    compare_flag(19) = 118
    compare_flag(20) = 68
    compare_flag(21) = 132
    compare_flag(22) = 101
    compare_flag(23) = 71
    compare_flag(24) = 132
    compare_flag(25) = 150

    print *, "Please enter a flag: "
    read *, input_flag

    do i = 1, 25
      input_flag_int(i) = ichar(input_flag(i:i+1), 2)
    end do

    do i = 1,25
      input_flag_int(i) = input_flag_int(i) + i
      if (input_flag_int(i) .ne. compare_flag(i)) then
        print *, "Sorry, flag does not match."
        call EXIT(1)
      end if
    end do

    print *, "Congrats, that was the flag!"

end program flag_checker_1
