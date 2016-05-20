#include <stdio.h>

#define MAX(__1,__2) ((__1 >= __2) ? __1 : __2)
#define MAX3(__1,__2,__3) MAX(MAX(__1,__2),__3)
#define MAX4(__1,__2,__3,__4) MAX(MAX(MAX(__1,__2),__3),__4)
#define MAX5(__1,__2,__3,__4,__5) MAX(MAX(MAX(MAX(__1,__2),__3),__4),__5)
#define MAX6(__1,__2,__3,__4,__5,__6) MAX(MAX(MAX(MAX(MAX(__1,__2),__3),__4),__5),__6)

#define MIN(__1,__2) ((__1 <= __2) ? __1 : __2)
#define MIN3(__1,__2,__3) MIN(MIN(__1,__2),__3)
#define MIN4(__1,__2,__3,__4) MIN(MIN(MIN(__1,__2),__3),__4)
#define MIN5(__1,__2,__3,__4,__5) MIN(MIN(MIN(MIN(__1,__2),__3),__4),__5)
#define MIN6(__1,__2,__3,__4,__5,__6) MIN(MIN(MIN(MIN(MIN(__1,__2),__3),__4),__5),__6)

int main(void)
{
	printf("Maksymalna: %d\n", MAX6(1, 2, 6, -3, 5, 4));
	printf("Minimalna: %d\n", MIN6(1, 2, 6, -3, 5, 4));
	return 0;
}