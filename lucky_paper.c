#include <stdio.h>
#include <stdlib.h>

int random_number(int range_from, int range_to);

float lucky_money(float left_money, int left_count);

int main() {
	float money, single_money;
	int n;
	scanf("%f",&money);
	scanf("%d",&n);
	while(n) {
		single_money = lucky_money(money,n--);
		printf("%.2f ",single_money);
		money -= single_money;
	}

	return 0;
}

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
	from = 1 * left_count;
	to = left_money * 100;
	return random_number(from, to) / 100.0f;
}
