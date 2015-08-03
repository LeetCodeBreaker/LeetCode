int hammingWeight(uint32_t n){
	int i,weight=0;
	for(i=0;i<32;i++){
		weight+=((n>>i)&1);
	}
	return weight;
}
