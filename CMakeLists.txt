cmake_minimum_required(VERSION 3.16)
project(AIA_n4s_2019 C)

set(CMAKE_C_STANDARD 11)

include_directories(include)

add_executable(AIA_n4s_2019
        include/my.h
        include/my_printf.h
        include/n4s.h
        lib/my/functions_printf.c
        lib/my/functions_printf_2.c
        lib/my/functions_printf_3.c
        lib/my/get_next_line.c
        lib/my/my_array_to_int.c
        lib/my/my_getnbr.c
        lib/my/my_itoa.c
        lib/my/my_printf.c
        lib/my/my_put_nbr.c
        lib/my/my_put_unsigned.c
        lib/my/my_putchar.c
        lib/my/my_putstr.c
        lib/my/my_revstr.c
        lib/my/my_str_to_word_array.c
        lib/my/my_strcat.c
        lib/my/my_strcmp.c
        lib/my/my_strcpy.c
        lib/my/my_strdup.c
        lib/my/my_strlen.c
        lib/my/my_strlenalphab.c
        lib/my/my_strncat.c
        lib/my/my_strncmp.c
        lib/my/my_strncpy.c
        lib/my/my_strtol.c
        lib/my/swap_elem.c
        lib/my/tools_tab.c
        src/check_end.c
        src/exec_cmd.c
        src/main.c
        src/trottle.c
        src/wheels_dir.c)
