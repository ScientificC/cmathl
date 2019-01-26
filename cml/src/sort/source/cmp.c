int
FUNCTION(cml_sort, cmp)(const void *a, const void *b)
{
        BASE b_a = *((const BASE *) a), b_b = *((const BASE *) b);

        if (b_a > b_b) {
                return 1;
        } else if (b_a < b_b) {
                return -1;
        } else {
                return 0;
        }

}
