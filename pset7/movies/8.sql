select name from people
join stars on people.id = stars.pesron_id
join movies on stars.person_id = movies.id
where movies.title = "Toy Story";
