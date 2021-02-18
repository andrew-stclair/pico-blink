# pico-blink

This is a rewritten version of the blink example code that adjusts the time delay between blink depending on an analogue input on A0.

It's designed to compare a counter to the analogue input every milisecond. if the counter is the same or bigger than the analogue input, it changes the state of the LED and resets the counter to 0.

This has the advantage of allowing the LED to cange as the analogue input changes, not every time it's sate changes.