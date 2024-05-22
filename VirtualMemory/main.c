int main() {
  int *kernel_ptr = (int *)0xC0000000;
  *kernel_ptr = 42;
}
