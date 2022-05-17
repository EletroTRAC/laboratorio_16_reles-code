const char indexHTML[] PROGMEM = R"=====(
    <!--
    ETEC Profa. Dra. Doroti Quiomi Kanashiro Toyohara

    Html de referência para o código.
-->
<!DOCTYPE html>
<html lang='pt-br'>

<head>
    <meta charset='UTF-8'>
    <meta http-equiv='X-UA-Compatible' content='IE=edge'>
    <meta name='viewport' content='width=device-width, initial-scale=1.0'>
    <title>Laboratorio 16</title>
    <style>
        * {
            margin: 0;
            padding: 0;
            box-sizing: border-box;
        }

        html,
        body {
            width: 100%;
            height: 100%;
        }

        body {
            background: #252525;
            font-family: 'Segoe UI', Tahoma, Geneva, Verdana, sans-serif;
        }

        .container {
            position: absolute;
            margin: 40px auto;
            top: 0;
            left: 0;
            right: 0;
            bottom: 0;
            background: rgba(0, 0, 0, 0.3);
            padding: 40px;
            max-width: 600px;
            max-height: 600px;
            border-radius: 4px;
            box-shadow: 0 4px 10px 4px rgba(186, 65, 9, 0.3);
        }

        .titulo {
            margin: auto;
            color: rgb(186, 65, 9);
            top: 22px;
            right: 0;
            bottom: 0;
            left: 22px;
        }

        .search {
            position: absolute;
            margin: auto;
            top: 0;
            right: 0;
            bottom: 0;
            left: 0;
            width: 80px;
            height: 80px;
            background: rgb(186, 65, 9);
            border-radius: 50%;
            transition: all 1s;
            z-index: 4;
            box-shadow: 0 0 25px 0 rgba(0, 0, 0, 0.4);
        }

        .search:hover {
            cursor: pointer;
        }

        .search::before {
            content: "";
            position: absolute;
            margin: auto;
            top: 22px;
            right: 0;
            bottom: 0;
            left: 22px;
            width: 12px;
            height: 2px;
            background: white;
            transform: rotate(45deg);
            transition: all .5s;
        }

        .search::after {
            content: "";
            position: absolute;
            margin: auto;
            top: -5px;
            right: 0;
            bottom: 0;
            left: -5px;
            width: 25px;
            height: 25px;
            border-radius: 50%;
            border: 2px solid white;
            transition: all .5s;
        }

        .procurar {
            position: absolute;
            margin: auto;
            top: 0;
            right: 0;
            bottom: 0;
            left: 0;
            width: 50px;
            height: 50px;
            outline: none;
            border: none;
            background: rgb(186, 65, 9);
            color: white;
            text-shadow: 0 0 10px rgb(186, 65, 9);
            padding: 0 80px 0 20px;
            border-radius: 30px;
            box-shadow: 0 0 25px 0 rgb(186, 65, 9),
                0 20px 25px 0 rgba(0, 0, 0, 0.2);
            transition: all 1s;
            opacity: 0;
            z-index: 5;
            font-weight: bolder;
            letter-spacing: 0.1em;
        }

        .procurar:hover {
            cursor: pointer;
        }

        .procurar:focus {
            width: 300px;
            opacity: 1;
            cursor: text;
        }

        .procurar:focus~.search {
            right: -250px;
            background: #151515;
            z-index: 6;
        }

        .procurar::before {
            top: 0;
            left: 0;
            width: 25px;
        }

        .procurar::after {
            top: 0;
            left: 0;
            width: 25px;
            height: 2px;
            border: none;
            background: white;
            border-radius: 0%;
            transform: rotate(-45deg);
        }

        .procurar::placeholder {
            color: white;
            opacity: 0.5;
            font-weight: bolder;
        }

        

        .parte-botoes {
            list-style: none;
            padding: 0;
            margin: 270px 50px 0 50px;
        }

        .parte-botoes:after {
            content: "";
            display: table;
            clear: both;
        }

        .parte-botoes li a {
            text-decoration: none;
            font-size: 19px;
            padding: 10px;
            text-align: center;
            color: #6a4d0f;
            cursor: pointer;
        }
    </style>
</head>

<body>
    <div class='container'>
        <div class="titulo">
            <h1>Lab 16 controle</h1>
        </div>
        <div class="procurar-bar">
            <input class="procurar" id="procurarbar" onkeyup="procurar_bancada()" type="text"
                placeholder="Procurar bancada...">
            <div class="search"></div>
        </div>
        <div class='parte-botoes'>
            <li>
                <a class='bancada' style="display: none;" href='/bc1'>Bancada 01</a>
                <a class='bancada' style="display: none;" href='/bc2'>Bancada 02</a>
                <a class='bancada' style="display: none;" href='/bc3'>Bancada 03</a>
                <a class='bancada' style="display: none;" href='/bc4'>Bancada 04</a>
                <a class='bancada' style="display: none;" href='/bc5'>Bancada 05</a>
                <a class='bancada' style="display: none;" href='/bc6'>Bancada 06</a>
                <a class='bancada' style="display: none;" href='/bc7'>Bancada 07</a>
                <a class='bancada' style="display: none;" href='/bc8'>Bancada 08</a>
                <a class='bancada' style="display: none;" href='/bc9'>Bancada 09</a>
                <a class='bancada' style="display: none;" href='/bc10'>Bancada 10</a>
                <a class='bancada' style="display: none;" href='/bc11'>Bancada 11</a>
                <a class='bancada' style="display: none;" href='/bc12'>Bancada 12</a>
            </li>
        </div>
    </div>
</body>
<script>
    function procurar_bancada() {
        var input = document.getElementById("procurarbar").value;
        input = input.toLowerCase();
        console.log(input);
        var x = document.getElementsByClassName("bancada");
        for (let i = 0; i < x.length; i++) {
            if (x[i].innerHTML.toLowerCase() == input) {
                x[i].style.display = "list-item";
            } else {
                x[i].style.display = "none";
            }
        }
    }
</script>

</html>
)=====" ;