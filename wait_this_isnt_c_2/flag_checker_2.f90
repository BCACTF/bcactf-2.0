program flag_checker_2
    implicit none

    integer(kind = 4) :: i, j, k
    character (len = 25) :: input_flag
    integer(kind = 4), dimension(5,-2:2) :: matrix_a, matrix_b, compare_flag
    integer(kind = 4), dimension(0:4, 0:4) :: matrix_c

    compare_flag(1,-2) = 2752
    compare_flag(1,-1) = 3290
    compare_flag(1, 0) = 4041
    compare_flag(1, 1) = 5221
    compare_flag(1, 2) = 7022

    compare_flag(2,-2) = 1913
    compare_flag(2,-1) = 2348
    compare_flag(2, 0) = 2977
    compare_flag(2, 1) = 3998
    compare_flag(2, 2) = 5570

    compare_flag(3,-2) = 2627
    compare_flag(3,-1) = 3088
    compare_flag(3, 0) = 3685
    compare_flag(3, 1) = 4620
    compare_flag(3, 2) = 6110

    compare_flag(4,-2) = 2137
    compare_flag(4,-1) = 2517
    compare_flag(4, 0) = 3010
    compare_flag(4, 1) = 3848
    compare_flag(4, 2) = 5077

    compare_flag(5,-2) = 2434
    compare_flag(5,-1) = 2910
    compare_flag(5, 0) = 3580
    compare_flag(5, 1) = 4608
    compare_flag(5, 2) = 6203

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

    i = 1
    do j = 0,4
      do k = 0,j
        matrix_c(j,k) = i
        matrix_c(k,j) = matrix_c(j,k)
        i = i+1
      end do
    end do

    ! do i = 0,4
    !   do j = 0,4
    !     write (*,*) matrix_c(i,j)
    !   end do
    ! end do

    matrix_b = matmul(matrix_a, matrix_c)

    ! print *, lbound(matrix_b)
    ! print *, shape(matrix_b)
    ! print *, ubound(matrix_b)
    !
    !
    ! do i = 1,5
    !   do j = -2,2
    !     write (*,*) matrix_b(i,j)
    !   end do
    ! end do

    if ( all(matrix_b .eq. compare_flag) ) then
      print *, "Congrats, that was the flag!"
      call EXIT(0)
    end if

    print *, "Sorry, flag does not match."

end program flag_checker_2
