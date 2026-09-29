# Write your MySQL query statement below
# DISTINCT shows distinct rows of data matching the condition 
SELECT DISTINCT author_id as id
FROM Views 
WHERE author_id = viewer_id
ORDER BY author_id