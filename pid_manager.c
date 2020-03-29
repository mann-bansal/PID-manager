int allocate_pid() {
	for(int i = 0; i < SIZE; i++) {
		if(bit_map1[i] == 0) { // just make sure that pid is available
			bit_map1[i] = 1; // Allocate a Pid to new process
      printf("New Process Allocated with PID : %d \n",(i+MIN_PID));
			return i + MIN_PID;
		}
	}
	return 1;
}
void release_pid(int pid1) {
    if(MIN_PID<=pid1<MAX_PID) {
      bit_map1[pid1-MIN_PID] = 0;
      printf("Process Released with PID : %d \n",pid1);
    }
