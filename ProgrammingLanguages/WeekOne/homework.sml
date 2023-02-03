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

fun number_in_months(dates: (int * int * int) list, months: int list) =
   let
       val x = 0
       fun step_over_the_dates(date: (int * int * int) list) =
           if not(null date)
           then (let
                    fun step_over_the_months(month: int list) =
                         if not(null month) andalso (hd month) = (#2 (hd date))
                            then x + 1 + step_over_the_months(tl month)
                         else if null (month)
                            then 0
                         else step_over_the_months(tl month)
                 in
                     step_over_the_months(months)
                 end) + step_over_the_dates(tl date)
            else if null (date)
                then 0
            else step_over_the_dates(tl date)
    in
        step_over_the_dates(dates)
    end


fun dates_in_month(dates: (int * int * int) list, month: int) =
    if not(null dates) andalso (#2 (hd dates)) = month
        then (hd dates)::dates_in_month(tl dates, month)
    else if null (dates)
        then []
    else dates_in_month(tl dates, month)
