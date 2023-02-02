fun is_older(fr: (int*int*int), ls: (int*int*int)) =
    if (#1 fr + #2 fr + #3 fr) < (#1 ls + #2 ls + #3 ls)
    then true
    else false

fun number_in_month(dates: (int * int * int) list, month: int) =
    let
        val x = 0
        fun get_list(date: (int * int * int) list) =
            if not(null date) andalso (#2 (hd date)) = month
                then x + 1 + get_list(tl date)
            else if null (date)
                then 0
            else get_list(tl date)
    in
        get_list(dates)
    end
