/**
 * GOAL: toggle PA19
 * PORT A = 0
 * PIN 19 = 19
 * 
 * PORT start at: 0x40002800
 */

typedef unsigned int uint32_t;
typedef volatile uint32_t RwReg;
#define REG_PORT_DIRSET0 (*(RwReg *)0x40002808UL) /**< \brief (PORT) Data Direction Set 0 */
#define REG_PORT_OUTCLR0 (*(RwReg *)0x40002814UL) /**< \brief (PORT) Data Output Value Clear 0 */
#define REG_PORT_OUTSET0 (*(RwReg *)0x40002818UL) /**< \brief (PORT) Data Output Value Set 0 */
#define REG_PORT_OUTTGL0 (*(RwReg *)0x4000281CUL) /**< \brief (PORT) Data Output Value Toggle 0 */

void delayUs(uint32_t delay)
{
  uint32_t numLoops;
  numLoops = delay;

  for (uint32_t i = 0; i < numLoops; i++)
    /* force compiler to not optimize this... */
    __asm__ __volatile__("");
}

void main()
{
  REG_PORT_DIRSET0 |= 1 << 19;
  for (;;)
  {
    delayUs(327680UL);
    REG_PORT_OUTTGL0 |= 1 << 19;
  }
}