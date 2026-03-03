#include "time.h"

using namespace std;

Stock::Stock() {
	next_num = 0;
}
void Stock::Add(int w, int v) {
	Box newBox(next_num, w, v);
	boxes.push_back(newBox);
	next_num++;
}
int Stock::GetByW(int min_w) {
	int best_index = -1;
	int best_W = 99999;
	int best_Num = 99999;

	for (int i = 0; i < boxes.size(); i++) {
		if (boxes[i].wi < best_W || (boxes[i].wi == best_W && boxes[i].num < best_Num)) {
			best_W = boxes[i].wi;
			best_Num = boxes[i].num;
			best_index = i;
		}
	}
    if (best_index != -1) {
        int result = boxes[best_index].num;
        boxes.erase(boxes.begin() + best_index);  
        return result;
    }

    return -1;  
}

int Stock::GetByV(int min_v) {
    int bestIndex = -1;
    int bestV = 999999;
    int bestNum = 999999;

    for (int i = 0; i < boxes.size(); i++) {
        if (boxes[i].vi >= min_v) {  
            if (boxes[i].vi < bestV ||
                (boxes[i].vi == bestV && boxes[i].num < bestNum)) {
                bestV = boxes[i].vi;
                bestNum = boxes[i].num;
                bestIndex = i;
            }
        }
    }

    if (bestIndex != -1) {
        int result = boxes[bestIndex].num;
        boxes.erase(boxes.begin() + bestIndex);
        return result;
    }

    return -1;
}