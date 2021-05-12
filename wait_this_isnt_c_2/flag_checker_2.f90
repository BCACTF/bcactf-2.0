program flag_checker_2
    implicit none

    integer(kind = 4) :: i, j, k
    character (len = 25) :: input_flag
    integer(kind = 4), dimension(5,-2:2) :: matrix_a, matrix_b, compare_flag
    compare_flag(1,-2) = 39739
    compare_flag(1,-1) = 52036
    compare_flag(1, 0) = 54026
    compare_flag(1, 1) = 47817
    compare_flag(1, 2) = 52096

    compare_flag(2,-2) = 31525
    compare_flag(2,-1) = 41848
    compare_flag(2, 0) = 44574
    compare_flag(2, 1) = 38500
    compare_flag(2, 2) = 42085

    compare_flag(3,-2) = 32329
    compare_flag(3,-1) = 44352
    compare_flag(3, 0) = 46438
    compare_flag(3, 1) = 40818
    compare_flag(3, 2) = 47399

    compare_flag(4,-2) = 29383
    compare_flag(4,-1) = 33197
    compare_flag(4, 0) = 37103
    compare_flag(4, 1) = 34311
    compare_flag(4, 2) = 35123

    compare_flag(5,-2) = 34428
    compare_flag(5,-1) = 47089
    compare_flag(5, 0) = 48032
    compare_flag(5, 1) = 41921
    compare_flag(5, 2) = 46292

    print *, "Please enter a flag: "
    read *, input_flag

    i = 0
    do j = 1,5
      do k = -2, 2
        matrix_a(j,k) = ichar(input_flag(i:i+1), 4)
        i = i+1
      end do
    end do

    matrix_a = transpose(matrix_a)

    do j = 1,5
      do k = -2, 2
        matrix_a(j,k) = matrix_a(j,k) + j*k
      end do
    end do

    matrix_a = cshift(matrix_a, shift = 2)

    matrix_b = matmul(matrix_a, matrix_a)

    if ( all(matrix_b .eq. compare_flag) ) then
      print *, "Congrats, that was the flag!"
      call EXIT(0)
    end if

    print *, "Sorry, flag does not match."

end program flag_checker_2
