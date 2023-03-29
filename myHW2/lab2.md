## Lab2 C++ openframeworks with boids

In this boids exercise, it is shown how individuals in the boid move according to the positions and speeds of their surrounding peers. I set up the movement of three different boids. I distinguish them with red, gray, and green colors and set different quantities. Define the individual's position, speed, acceleration and separation, alignment, and cohesion.

I set 3 boids to different relationships. Himself, friendly and hostile. I use a for loop to express the movement of the boids. In the interaction of the boid， if they exclude the interaction with themselves, according to the different distances set, we can see the movement of separation, alignment, and cohesion with other boids. In interactions among friendly boids, they did not preclude interaction with themselves. In a hostile relationship, they have only separation.
