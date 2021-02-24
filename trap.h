


class Trap: public Item{
	private:
		int statusCaused;
		Potion pot;
		
	Public:
		Trap(int statusC){
			statusCaused = statusC;
			Potion pot = new Potion(id,name);
		}
		~Trap();
		Item getItem(){
			return pot;
		}
		int getStatus(){
			return statusCaused; 
		}
};
