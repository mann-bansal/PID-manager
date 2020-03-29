int bit_map1[SIZE];

int allocate_map() {
	for(int i = 0; i < SIZE; i++) {
		bit_map1[i] = 0; // Mark all as Available in Bitmap
	}
  printf("Process Bitmap initialized... \n");
	return 1;
}
