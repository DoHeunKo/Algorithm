-- 코드를 입력하세요
SELECT product_code,sum(price*sales_amount)as sales from product p inner join offline_sale os
on p.product_id=os.product_id
group by product_code
order by 2 desc,1 asc
