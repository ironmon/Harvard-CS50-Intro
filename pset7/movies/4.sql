SELECT COUNT(title) from movies
join ratings on movies.id = ratings.movie_id
WHere rating = 10;