# Lucky Money Algorithm Implementation #

## Original Intention ##

I have being notified for serveral times of a mock implementation of Wechat Lucky Money algorithm. And I considered if the problem's complex as they explained. I found that the Lucky Money Algorithm can be simply implemented due to the following causes (I just talk about random amount type here). As for random size, there is no need to take care of the steady of the amount of money each people get. So we can split the whole money distribution process just consider the money each time a people gets.

Each time, the algorithm returns a number range from 0.01 to left_money - (left_count - 1) * 0.01. This guarantees the left user could at least get (￥/$)0.01. The code below is the implementation of this algorithm.

```c
/* integer number from range_from to range_to */
int random_number(int range_from, int range_to) {
    srand(time(NULL));
    return (rand() % (range_to + 1) + range_from);
}

/* left_money is the money availible 
left_count is how many people didn't draw the money 
*/
float lucky_money(float left_money, int left_count) {
    int from, to;
    if (left_count == 1) return left_money;
    from = 1;
    to = left_money * 100 - (--left_count);
    return random_number(from, to) / 100.0f;
}
```