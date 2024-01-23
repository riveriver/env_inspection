SET PATH=C:\EMB\EDE\Keil\Keil536\ARM\ARMCC\Bin;D:\EMB\DEV\VMware\bin\;C:\WINDOWS\system32;C:\WINDOWS;C:\WINDOWS\System32\Wbem;C:\WINDOWS\System32\WindowsPowerShell\v1.0\;C:\WINDOWS\System32\OpenSSH\;C:\Software\Bandizip\;C:\EMB\EDE\Git\cmd;C:\EMB\EDE\anoconda;C:\EMB\EDE\anoconda\Library\mingw-w64\bin;C:\EMB\EDE\anoconda\Library\usr\bin;C:\EMB\EDE\anoconda\Library\bin;C:\EMB\EDE\anoconda\Scripts;C:\Users\Davon.Y\AppData\Local\Microsoft\WindowsApps;C:\EMB\EDE\Microsoft VS Code\bin;C:\EMB\EDE\MSYS2\mingw64\bin;C:\EMB\EDE\pycharm\PyCharm Community Edition 2023.2\bin;;
SET ARMCC5_ASMOPT=--diag_suppress=9931
SET ARMCC5_CCOPT=--diag_suppress=9931
SET ARMCC5_LINKOPT=--diag_suppress=9931
SET CPU_TYPE=STM32F103C8
SET CPU_VENDOR=STMicroelectronics
SET UV2_TARGET=ADC-DEMO
SET CPU_CLOCK=0x007A1200
"C:\EMB\EDE\Keil\Keil536\ARM\ARMCC\Bin\ArmAsm" --Via ".\startup_stm32f10x_md._ia"
"C:\EMB\EDE\Keil\Keil536\ARM\ARMCC\Bin\ArmCC" --Via ".\main.__i"
"C:\EMB\EDE\Keil\Keil536\ARM\ARMCC\Bin\ArmCC" --Via ".\led.__i"
"C:\EMB\EDE\Keil\Keil536\ARM\ARMCC\Bin\ArmCC" --Via ".\usart1.__i"
"C:\EMB\EDE\Keil\Keil536\ARM\ARMCC\Bin\ArmCC" --Via ".\delay.__i"
"C:\EMB\EDE\Keil\Keil536\ARM\ARMCC\Bin\ArmCC" --Via ".\dht11.__i"
"C:\EMB\EDE\Keil\Keil536\ARM\ARMCC\Bin\ArmCC" --Via ".\sys.__i"
"C:\EMB\EDE\Keil\Keil536\ARM\ARMCC\Bin\ArmCC" --Via ".\stm32f10x_it.__i"
"C:\EMB\EDE\Keil\Keil536\ARM\ARMCC\Bin\ArmCC" --Via ".\stm32f10x_gpio.__i"
"C:\EMB\EDE\Keil\Keil536\ARM\ARMCC\Bin\ArmCC" --Via ".\stm32f10x_rcc.__i"
"C:\EMB\EDE\Keil\Keil536\ARM\ARMCC\Bin\ArmCC" --Via ".\stm32f10x_usart.__i"
"C:\EMB\EDE\Keil\Keil536\ARM\ARMCC\Bin\ArmCC" --Via ".\stm32f10x_adc.__i"
"C:\EMB\EDE\Keil\Keil536\ARM\ARMCC\Bin\ArmCC" --Via ".\stm32f10x_dma.__i"
"C:\EMB\EDE\Keil\Keil536\ARM\ARMCC\Bin\ArmCC" --Via ".\stm32f10x_flash.__i"
"C:\EMB\EDE\Keil\Keil536\ARM\ARMCC\Bin\ArmCC" --Via ".\stm32f10x_rtc.__i"
"C:\EMB\EDE\Keil\Keil536\ARM\ARMCC\Bin\ArmCC" --Via ".\misc.__i"
"C:\EMB\EDE\Keil\Keil536\ARM\ARMCC\Bin\ArmCC" --Via ".\stm32f10x_tim.__i"
"C:\EMB\EDE\Keil\Keil536\ARM\ARMCC\Bin\ArmCC" --Via ".\stm32f10x_exti.__i"
"C:\EMB\EDE\Keil\Keil536\ARM\ARMCC\Bin\ArmCC" --Via ".\core_cm3.__i"
"C:\EMB\EDE\Keil\Keil536\ARM\ARMCC\Bin\ArmCC" --Via ".\system_stm32f10x.__i"
"C:\EMB\EDE\Keil\Keil536\ARM\ARMCC\Bin\ArmLink" --Via ".\STM32-DEMO.lnp"
"C:\EMB\EDE\Keil\Keil536\ARM\ARMCC\Bin\fromelf.exe" ".\STM32-DEMO.axf" --i32combined --output ".\STM32-DEMO.hex"
