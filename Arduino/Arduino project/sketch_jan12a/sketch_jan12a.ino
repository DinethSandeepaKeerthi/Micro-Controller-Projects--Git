// LCD module connections
sbit LCD_RS at RB0_bit;
sbit LCD_EN at RB1_bit;
sbit LCD_D4 at RB2_bit;
sbit LCD_D5 at RB3_bit;
sbit LCD_D6 at RB4_bit;
sbit LCD_D7 at RB5_bit;
sbit LCD_RS_Direction at TRISB0_bit;
sbit LCD_EN_Direction at TRISB1_bit;
sbit LCD_D4_Direction at TRISB2_bit;
sbit LCD_D5_Direction at TRISB3_bit;
sbit LCD_D6_Direction at TRISB4_bit;
sbit LCD_D7_Direction at TRISB5_bit;
// End LCD module connections

unsigned int inputsignal = 0;
unsigned int firstRun = 1;
unsigned int cnt = 0; // Define variable cnt == 1KHz clk
long HR = 0;
char *text;
unsigned char outlcd;
char uart_rd;
char uart_rd1[15];

void interrupt() {
    cnt++;           // Interrupt causes cnt to be incremented by 1
    TMR0 = 194;      // Timer TMR0 is returned to its initial value
    INTCON.T0IF = 0; // Bit T0IF is cleared
}

void main() {
    OPTION_REG = 0x84; // Prescaler is assigned to timer TMR0
    ADCON0 = 0x81;    // Pins AN1 is configured as analog
    TRISA = 0xFF;     // All port A pins are configured as inputs
    ADCON1 = 0x00;
    TRISD = 0; // All port D pins are configured as outputs
    PORTD = 0; // Reset port D
    UART1_Init(9600);
    delay_ms(100);

    Lcd_Init();              // LCD display initialization
    Lcd_Cmd(_LCD_CURSOR_OFF); // LCD command (cursor off)
    Lcd_Cmd(_LCD_CLEAR);      // LCD command (clear LCD)

    text = "WELCOME...... "; // Define the first message
    Lcd_Cmd(_LCD_CLEAR);
    Lcd_Out(1, 2, text); // Write the first message on the first line
    text = "HEART BEAT METER";
    Lcd_Out(2, 1, text);
    delay_ms(500);

    while (1) {
        inputsignal = ADC_Read(1);
        if (inputsignal >= 64) {
            delay_ms(50);
            if (firstRun == 1) {
                firstRun = 0;
                cnt = 0;      // Variable cnt is assigned 0
                TMR0 = 194;   // Timer T0 counts from 194 to 255
                INTCON = 0xA0; // Enable interrupt TMR0
            } else {
                // Find heart rate
                Lcd_Cmd(_LCD_CLEAR);
                text = "Heart rate=";
                Lcd_Out(1, 1, text);
                HR = 60000 / cnt;     // Number of interrupts is time between two pulses in ms
                outlcd = HR / 100;    // Hundreds digit in HR
                Lcd_Chr(1, 12, 48 + outlcd); // Write result in ASCII format
                outlcd = (HR / 10) % 10; // Tens digit in HR
                Lcd_Chr_CP(48 + outlcd);
                outlcd = HR % 10; // Ones digit in HR
                Lcd_Chr_CP(48 + outlcd);
                Lcd_out(2, 5, "puls/min.");

                // Reset value of counter and start the next test
                cnt = 0;
                TMR0 = 194;   // Timer T0 counts from 194 to 255
                INTCON = 0xA0; // Enable interrupt TMR0
            }
        }
    }
}
