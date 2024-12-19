csv <- read.csv("comp305Ws3.csv")


csvColumns <- c("ParticleNumber", "FPS")
print(csvColumns)


library(ggplot2)

ggplot(csv, aes(x = ParticleNumber, y = FPS)) +
  geom_line(color = "black") +
  theme_minimal() +
  labs(
    title = "Amount of Particles Against FPS Value",
    x = "Number of Particles",
    y = "FPS"
  ) +
  theme(axis.text.x = element_text(hjust = 1)) 
