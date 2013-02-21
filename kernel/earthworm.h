/* struct definitions for managing transparent proxies */

#define EW_START   0x01
#define EW_STOP    0x02
#define EW_NOMAGIC 0x00

  // 0 false
  // 1 magic start
  // 2 magic stop
#define IRELEVANT 0x00
#define IN        0x01
#define OUT       0x02

struct ew_rule {
  //uint32_t id; /* rule id   */
  char * ip;
  char * pt;
  //uint32_t ip; /* ip addr   */
  //uint16_t pt; /* port      */
  uint8_t  dr; /* direction */
  //uint8_t  ac; /* active    */
};

struct ew_rules {
  struct ew_rule * rule;
  struct list_head list;
};
