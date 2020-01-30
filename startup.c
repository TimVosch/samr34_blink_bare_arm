extern unsigned int _DATA_ROM_START;
extern unsigned int _DATA_RAM_START;
extern unsigned int _DATA_RAM_END;
extern unsigned int _BSS_START;
extern unsigned int _BSS_END;

#define STACK_TOP 0x20008000

// Predefine startup function
void startup();

/**
 * Define vector table
 */
unsigned int *vectorTable[2] __attribute__((section("vectors"))) = {
    (unsigned int *)STACK_TOP, // Stack pointer
    (unsigned int *)(&startup) // Reset vector
};

void main();

void startup()
{
  // Create pointers for sections
  unsigned int *data_rom_start_p = &_DATA_ROM_START;
  unsigned int *data_ram_start_p = &_DATA_RAM_START;
  unsigned int *data_ram_end_p = &_DATA_RAM_END;

  unsigned int *_bss_start_p = &_BSS_START;
  unsigned int *_bss_end_p = &_BSS_END;

  // Copy .data from ROM to RAM
  while (data_ram_start_p != data_ram_end_p)
  {
    *data_ram_start_p = *data_rom_start_p;
    data_ram_start_p++;
    data_rom_start_p++;
  }

  // Initialize .bss with nulls
  while (_bss_start_p != _bss_end_p)
  {
    *_bss_start_p = 0;
    _bss_start_p++;
  }

  // Call main function
  main();
}