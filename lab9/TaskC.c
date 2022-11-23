#include <stdio.h>

int Abs(int x);
int Min(int x, int y);
int Max(int x, int y);
int Sign(int x);
void DoCalculations(int* i, int* j, int* l, int g);

int main() {
	int i = -25;
	int j = -9;
	int l = -8;
	int i1, i2, g;
	for (g = 1; g < 51; g++) {
		DoCalculations(&i, &j, &l, g);
		i1 = -10 - j;
		i2 = -20 - j;
		if ((i2 <= i) && (i <=i1)) { printf("%s%c%s%i%c%s%i%c%i%c%i", "Hitted!", '\n', "Time is ", g, '\n', "Coordinates and parameter (i, j, l) = ", i, ' ', j, ' ', l); return 0; }
	}
	printf("%s\n%s%i\n%s%i%c%i%c%i", "Missed!", "Time is ", g, "Coordinates and parameter (i, j, l) = ", i, ' ', j, ' ', l);
	return 0;
}

void DoCalculations(int* i, int* j, int* l, int g) {
	int i0 = *i;
	int j0 = *j;
	int l0 = *l;
	*i = ((Abs(i0 - j0) * l0 - Abs(j0 - l0) * i0 + Abs(i0 - l0) * j0) % 20) - g + 1;
	*j = (Min(i0, j0) * Max(j0, l0) * Min(i0, l0)) % 25 + 5 * Sign(i0) + g - 1;
	*l = Abs(l0) * Sign(i0 - j0) - Abs(i0) * Sign(j0 - l0) + Abs(j0) * Sign(i0 - l0);
}
int Abs(int x) {
	if (x >= 0) { return x; }
	else { return -x; }
}
int Min(int x, int y) {
	if (x >= y) { return y; }
	else { return x; }
}
int Max(int x, int y) {
	if (x >= y) { return x; }
	else { return y; }
}
int Sign(int x) {
	if (x >= 0) { return 1; }
	else { return -1; }
}