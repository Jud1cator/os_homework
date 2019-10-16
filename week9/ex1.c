#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define LEFTMOST_AGE_BIT 65536

/*

Implementation of ageing algorithm with log2(LEFTMOST_AGE_BIT) age.

*/

struct page {
    int R;
    int addr;
    int age;
};

// initialize the memory
void mem_init(struct page memory[], int mem_cap) {
    for(int i = 0; i < mem_cap; i++) {
        memory[i].R = 0;
        memory[i].addr = 0;
        memory[i].age = 0;
    }
}

// add page to the memory if there is a hole
void mem_add(int p_addr, struct page memory[], int mem_cap) {
    for(int i = 0; i < mem_cap; i++) {
        if(memory[i].addr == 0) {
            memory[i].addr = p_addr;
            memory[i].R = 1;
            memory[i].age = LEFTMOST_AGE_BIT;
            break;
        }
    }
}

// add page to the memory if memory is full
void mem_swap(int p_addr, struct page memory[], int mem_cap) {
    int min_age = LEFTMOST_AGE_BIT * 2, min_idx;
    for(int i = 0; i < mem_cap; i++) {
        if(min_age > memory[i].age) {
            min_age = memory[i].age;
            min_idx = i;
        }
    }
    memory[min_idx].addr = p_addr;
    memory[min_idx].R = 1;
    memory[min_idx].age = LEFTMOST_AGE_BIT;
}

// update R bits
void mem_upd(struct page memory[], int mem_cap) {
    for(int i = 0; i < mem_cap; i++) {
        memory[i].R = 0;
        memory[i].age >>= 1;
    }
}

// return index of p_addr page if it is in memory, -1 otherwise
int find_page(int p_addr, struct page memory[], int mem_cap) {
    for(int i = 0; i < mem_cap; i++) 
        if(memory[i].addr == p_addr) return i;
    return -1;
}

void print_mem(struct page memory[], int mem_cap) {
    printf("Current memory state:\n");
    printf("Addr's: ");
    for(int i = 0; i < mem_cap; i++) {
        printf("%d ", memory[i].addr);
    }
    printf("\nR's   : ");
    for(int i = 0; i < mem_cap; i++) {
        printf("%d ", memory[i].R);
    }
    printf("\nAges  : ");
    for(int i = 0; i < mem_cap; i++) {
        printf("%d ", memory[i].age);
    }
    printf("\n\n");
}

int main(int argc, char *argv[]) {
    int frames, hit = 0, miss = 0;
    frames = atoi(argv[1]);
    struct page memory[frames];
    
    FILE *in;
    if((in = fopen("input2.txt", "r")) == NULL) exit(1);
    
    mem_init(memory, frames);
    print_mem(memory, frames);
    
    int cur_p, p_count = 0;
    while(fscanf(in, "%d", &cur_p) != EOF) {
        printf("Adding page %d\n", cur_p);
        int idx;
        // if referenced page is in memory, update its age
        if((idx = find_page(cur_p, memory, frames)) > -1) {
            printf("Hit!\n");
            hit++;
            memory[idx].R = 1;
            memory[idx].age >>= 1;
            memory[idx].age += LEFTMOST_AGE_BIT; // 1 leftmost bit added         
        } else {
            printf("Miss!\n");
            miss++;
            // if page is not in memory, but there is a space
            if(p_count < frames) {
                mem_add(cur_p, memory, frames);
                p_count++;
            } 
            // if there is no space left
            else mem_swap(cur_p, memory, frames);
        }
            
        // update ages
        mem_upd(memory, frames);
        print_mem(memory, frames);
    }
    
    printf("Number of frames: %d\nHits: %d\nMisses: %d\nHit percentage: %.3f\n",     
        frames, hit, miss, (float) hit / (float) (hit + miss));
        
    if(miss == 0) printf("I guess they never miss, ha!\n");

    fclose(in);
    return 0;
}
