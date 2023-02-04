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


fun dates_in_months(dates: (int * int * int) list, months: int list) =
   if null months
   then []
   else dates_in_month(dates, hd months) @ dates_in_months(dates, tl months)

fun get_nth(words: string list, nth: int) =
    let
        fun get_word(word: string list, element: int) =
            if element = nth
            then hd word
            else get_word(tl word, element + 1)
    in
        get_word(words, 1)
    end

fun date_to_string(date: int * int * int) =
    let
        val months = ["January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"]
    in
        get_nth(months, (#2 date)) ^ " " ^ Int.toString(#3 date) ^ ", " ^ Int.toString(#1 date)
    end

fun number_before_reaching_sum(sum: int, num: int list) =
    let fun num_helper(sum: int, number_list: int list, running: int, index: int) =
	    if running >= sum
	    then index - 1
	    else num_helper(sum, tl number_list, running + hd number_list, index+1)
    in num_helper(sum, num, 0, 0)
    end

fun what_month(day: int) =
    let
        val months = [31,28,31,30,31,30,31,31,30,31,30,31]
    in
         number_before_reaching_sum(day, months)
    end
