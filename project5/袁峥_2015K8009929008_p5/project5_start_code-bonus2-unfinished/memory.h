/* Author(s): <Your name here>
 * Defines the memory manager for the kernel.
*/

#ifndef MEMORY_H
#define MEMORY_H

enum {
  /* physical page facts */
  PAGE_SIZE = 4096,
  PAGE_N_ENTRIES = (PAGE_SIZE / sizeof(uint32_t)),

  // Global bit
  PE_G = (0x40 >> 6),
  // Valid bit
  PE_V = (0x80 >> 6),
  // Writable bit
  PE_D = (0x100 >> 6),
  // Uncache bit
  PE_UC = (0x400 >> 6),



  /* Constants to simulate a very small physical memory. */
  PAGEABLE_PAGES = 7,



  PAGE_MASK = 0xfffff000,
  PID_MASK = 0x00000ff0,
  FLAG_MASK = 0x0000000f,
  PE_BASE_ADDR_MASK = 0xfffff000,
  MODE_MASK = 0x000003ff,  
  on_demand = TRUE

  
};

/* TODO: Structure of an entry in the page map */
typedef struct {
    // design here
    node_t node;
	uint32_t vaddr;
	uint32_t index;
	bool_t used;
	bool_t pinned;
	bool_t readed;
	int pid;
	uint32_t page_directory;
} page_map_entry_t;
extern page_map_entry_t page_map[ PAGEABLE_PAGES ];


/* Prototypes */

/* Return the physical address of the i-th page */
uint32_t page_paddr(int i);

uint32_t page_vaddr(int i);


/* Allocate a page.  If necessary, swap a page out.
 * On success, return the index of the page in the page map.  On
 * failure, abort.  BUG: pages are not made free when a process
 * exits.
 */
int page_alloc(bool_t pinned);

/* init page_map */
uint32_t init_memory(void);

/* Set up a page directory and page table for the given process. Fill in
 * any necessary information in the pcb. 
 */
uint32_t *setup_page_table(int pid);

// other functions defined here
//
void do_page_fault(uint32_t vaddr);

void print_page_map();

#endif /* !MEMORY_H */
