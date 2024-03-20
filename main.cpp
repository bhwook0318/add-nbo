#include <stdio.h>
#include <stdint.h>
#include <stddef.h>
#include <netinet/in.h>

int main(int argc, char** argv) {
	if (argc != 3)
		printf("input must be two");
	else {
		FILE *f1, *f2;
		uint8_t buf1[32], buf2[32];
		f1 = fopen(argv[1], "rb");
		f2 = fopen(argv[2], "rb");
		fread(buf1, 1, 32, f1);
		fread(buf2, 1, 32, f2);
		
		uint32_t *p1 = reinterpret_cast<uint32_t*>(buf1);
		uint32_t *p2 = reinterpret_cast<uint32_t*>(buf2);

		uint32_t num1 = ntohl(*p1);
		uint32_t num2 = ntohl(*p2);
		uint32_t sum = num1 + num2;
		printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", num1, num1, num2, num2, sum, sum);

		fclose(f1);
		fclose(f2);
	}
	return 0;
}
