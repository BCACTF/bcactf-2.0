program flag_checker_1
    implicit none

    integer(kind = 2) :: i
    character (len = 25) :: input_flag
    integer(kind = 2), dimension(25) :: input_flag_int, compare_flag
    compare_flag = (/99,101,100,103,121,108,130,110,57,124,127,126,65,92,110, &
    121, 70, 113, 118, 68, 132, 101, 71, 132, 150/)

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
