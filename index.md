Last updated: Jun 24 11:29:38
# Marble Music Machine
For full documentation visit [this](https://docs.google.com/document/d/19l-sdvGk2wv6FiNkObK4XHLtHroH8l88qlTdeSVrPsI/edit?tab=t.0#heading=h.u3em2oo7d9ti) google document 
This is a music machine that replays the notes you input by dropping marbles onto a Xylophone! Rather than playing directly on the xylophone, you pre-program notes by pushing buttons. After you are done, you press the stop button twice (once to stop and once to start playing) then watch as balls are sent bouncing off the keys of the xylophone. This will loop forever because of the ball lift on the side!

You should comment out all portions of your portfolio that you have not completed yet, as well as any instructions:
```HTML 
Milestones:
Milestone 1: Program button interface to record and store notes
Milestone 2: Design method for dropping balls onto the xylophone. Design method to control where the balls drop to (to drop on different notes)
Milestone 3: Connect that movement to the arduino for the final design!
```

| Vikram D | Hillbrook School | Civil and Mechanical Engineering | Incoming Sophomore |
|:--:|:--:|:--:|:--:|

**Replace the BlueStamp logo below with an image of yourself and your completed project. Follow the guide [here](https://tomcam.github.io/least-github-pages/adding-images-github-pages-site.html) if you need help.**

![Headstone Image](logo.svg)
  
# Final Milestone

**Don't forget to replace the text below with the embedding for your milestone video. Go to Youtube, click Share -> Embed, and copy and paste the code to replace what's below.**

<iframe width="560" height="315" src="https://www.youtube.com/embed/F7M7imOVGug" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>

For your final milestone, explain the outcome of your project. Key details to include are:
- What you've accomplished since your previous milestone
- What your biggest challenges and triumphs were at BSE
- A summary of key topics you learned about
- What you hope to learn in the future after everything you've learned at BSE



# Second Milestone

**Don't forget to replace the text below with the embedding for your milestone video. Go to Youtube, click Share -> Embed, and copy and paste the code to replace what's below.**

<iframe width="560" height="315" src="https://www.youtube.com/embed/y3VAmNlER5Y" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>

For your second milestone, explain what you've worked on since your previous milestone. You can highlight:
- Technical details of what you've accomplished and how they contribute to the final goal
- What has been surprising about the project so far
- Previous challenges you faced that you overcame
- What needs to be completed before your final milestone 

# First Milestone

**Don't forget to replace the text below with the embedding for your milestone video. Go to Youtube, click Share -> Embed, and copy and paste the code to replace what's below.**

<iframe width="560" height="315" src="https://www.youtube.com/embed/CaCazFBhYKs" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>

I planned to build my project in two stages: The coding stage and the design and building stage. During the coding stage, I worked on programming the arduino to receive inputs from a button, and then replay it on a servo. I started with one buttton and one servo. The code was quite simple as I just needed to record one variable: the gap between the button presses. I used an array to store the values.

However, as I got more buzzers, I had to calculate and store more gaps. I needed more arrays, more wires, and more control over the servos.



# Schematics 
Here's where you'll put images of your schematics. [Tinkercad](https://www.tinkercad.com/blog/official-guide-to-tinkercad-circuits) and [Fritzing](https://fritzing.org/learning/) are both great resoruces to create professional schematic diagrams, though BSE recommends Tinkercad becuase it can be done easily and for free in the browser. 

# Code
Here's where you'll put your code. The syntax below places it into a block of code. Follow the guide [here]([url](https://www.markdownguide.org/extended-syntax/)) to learn how to customize it to your project needs. 

```c++
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Hello World!");
}

void loop() {
  // put your main code here, to run repeatedly:

}
```

# Bill of Materials
Here's where you'll list the parts in your project. To add more rows, just copy and paste the example rows below.
Don't forget to place the link of where to buy each component inside the quotation marks in the corresponding row after href =. Follow the guide [here]([url](https://www.markdownguide.org/extended-syntax/)) to learn how to customize this to your project needs. 

| **Part** | **Note** | **Price** | **Link** |
|:--:|:--:|:--:|:--:|
| Item Name | What the item is used for | $Price | <a href="https://www.amazon.com/Arduino-A000066-ARDUINO-UNO-R3/dp/B008GRTSV6/"> Link </a> |
| Item Name | What the item is used for | $Price | <a href="https://www.amazon.com/Arduino-A000066-ARDUINO-UNO-R3/dp/B008GRTSV6/"> Link </a> |
| Item Name | What the item is used for | $Price | <a href="https://www.amazon.com/Arduino-A000066-ARDUINO-UNO-R3/dp/B008GRTSV6/"> Link </a> |

# Other Resources/Examples
One of the best parts about Github is that you can view how other people set up their own work. Here are some past BSE portfolios that are awesome examples. You can view how they set up their portfolio, and you can view their index.md files to understand how they implemented different portfolio components.
- [Example 1](https://trashytuber.github.io/YimingJiaBlueStamp/)
- [Example 2](https://sviatil0.github.io/Sviatoslav_BSE/)
- [Example 3](https://arneshkumar.github.io/arneshbluestamp/)

To watch the BSE tutorial on how to create a portfolio, click here.

# Starter Project – Retro Arcade Console
<iframe width="800" height="315" src="https://www.youtube.com/embed/-vWqwQfv9GA?si=EgtACB9ZjJk6BhVi" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" referrerpolicy="strict-origin-when-cross-origin" allowfullscreen></iframe>

This console has multiple games on like Snake and Tetris. The parts and code were preloaded and all I needed to do was solder different pieces to the main PCB. It can be powered thorugh a mini-USB port or 3AAA batteries.

<div style="text-align:left"><img src="starter_1_2.png" alt="front of the starter project" width="1500"/> </div>

This gave me a great way to practice my soldering skills as there were many points I had to solder together. The most challenging part of soldering each contraption while keeping them in place and alligned. The pins were also extremely close together, and I had never had to solder with this much precision before. Attaching the battery was also difficult as I decided to shorten the wire. This meant that I needed to cut the while and re-solder it together. Because I had already attached the wires to the PCB and the battery, soldering them back together was very difficult as I had to position them between the battery and the PCB. I had very little room. However, it turned out great and all the components work!

