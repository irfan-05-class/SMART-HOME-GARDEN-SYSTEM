/* Soil moisture thresholds (calibrate later) */
#define SOIL_WET_THRESHOLD   1500
#define SOIL_DRY_THRESHOLD   2500

/* Soil condition states */
typedef enum
{
    SOIL_WET = 0,
    SOIL_OK,
    SOIL_DRY
} SoilState_t;

/* Global variables for system use */
uint16_t soil_raw_value = 0;
SoilState_t soil_state;

/* Initialize ADC for soil moisture sensor (PA0) */
void SoilSensor_Init(void)
{
    /* Enable GPIOA clock */
    //RCC->AHB1ENR |= (1 << 0);

    /* PA0 → Analog mode */
    GPIOA->MODER |= (3 << (0 * 2));

    /* Enable ADC1 clock */
    RCC->APB2ENR |= (1 << 8);

    /* ADC basic configuration */
    ADC1->CR2 = 0;
    ADC1->SQR3 = 0;          // Channel 0 (PA0)
    ADC1->CR2 |= (1 << 0);   // ADC ON
}

/* Read soil moisture sensor (ADC) */
uint16_t SoilSensor_Read(void)
{
    ADC1->CR2 |= (1 << 30);          // Start conversion
    while (!(ADC1->SR & (1 << 1)));  // Wait for EOC
    return ADC1->DR;
}

/* Update soil condition */
void SoilSensor_Update(void)
{
    soil_raw_value = SoilSensor_Read();

    if (soil_raw_value > SOIL_DRY_THRESHOLD)
    {
        soil_state = SOIL_DRY;
    }
    else if (soil_raw_value < SOIL_WET_THRESHOLD)
    {
        soil_state = SOIL_WET;
    }
    else
    {
        soil_state = SOIL_OK;
    }
}
