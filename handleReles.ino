/* ---------------------------------------------------------
  ETEC Profa. Dra. Doroti Quiomi Kanashiro Toyohara

  Funções de controle das bancadas/reles
--------------------------------------------------------- */

void handleRele1(void) {
  BC1_status = !BC1_status;
  digitalWrite(BC[0], BC1_status);
  Serial.println("Toggle Rele1");
  server.send(200, "text/html", indexHTML);
}

void handleRele2(void) {
  BC2_status = !BC2_status;
  digitalWrite(BC[1], BC2_status);
  Serial.println("Toggle Rele2");
  server.send(200, "text/html", indexHTML);
}

void handleRele3(void) {
  BC3_status = !BC3_status;
  digitalWrite(BC[2], BC3_status);
  Serial.println("Toggle Rele3");
  server.send(200, "text/html", indexHTML);
}

void handleRele4(void) {
  BC4_status = !BC4_status;
  digitalWrite(BC[3], BC4_status);
  Serial.println("Toggle Rele4");
  server.send(200, "text/html", indexHTML);
}

void handleRele5(void) {
  BC5_status = !BC5_status;
  digitalWrite(BC[4], BC5_status);
  Serial.println("Toggle Rele5");
  server.send(200, "text/html", indexHTML);
}

void handleRele6(void) {
  BC6_status = !BC6_status;
  digitalWrite(BC[5], BC6_status);
  Serial.println("Toggle Rele6");
  server.send(200, "text/html", indexHTML);
}

void handleRele7(void) {
  BC7_status = !BC7_status;
  digitalWrite(BC[6], BC7_status);
  Serial.println("Toggle Rele7");
  server.send(200, "text/html", indexHTML);
}

void handleRele8(void) {
  BC8_status = !BC8_status;
  digitalWrite(BC[7], BC8_status);
  Serial.println("Toggle Rele8");
  server.send(200, "text/html", indexHTML);
}

void handleRele9(void) {
  BC9_status = !BC9_status;
  digitalWrite(BC[8], BC9_status);
  Serial.println("Toggle Rele9");
  server.send(200, "text/html", indexHTML);
}

void handleRele10(void) {
  BC10_status = !BC10_status;
  digitalWrite(BC[9], BC10_status);
  Serial.println("Toggle Rele10");
  server.send(200, "text/html", indexHTML);
}

void handleRele11(void) {
  BC11_status = !BC11_status;
  digitalWrite(BC[10], BC11_status);
  Serial.println("Toggle Rele11");
  server.send(200, "text/html", indexHTML);
}

void handleRele12(void) {
  BC12_status = !BC12_status;
  digitalWrite(BC[11], BC12_status);
  Serial.println("Toggle Rele12");
  server.send(200, "text/html", indexHTML);
}

String PageReturn(void) {
  String Page;
  Page += F("<!DOCTYPE html>"
            "<html lang='pt-br'>"
            "<head>"
            "    <meta charset='UTF-8'>"
            "    <meta http-equiv='X-UA-Compatible' content='IE=edge'>"
            "    <meta name='viewport' content='width=device-width, initial-scale=1.0'>"
            "    <title>Laboratorio 16</title>"
            "    <style>"
            "       .bcon{ color: green; }"
            "       .bcoff{ color: red; }"
            "    </style>"
            "</head>"
            "<body>"
            "    <div class='container'>"
            "        <h1>Lab 16 controle</h1>"
            "        <div class='parte-botoes'>"
            "<div class='coluna-esquerda'>");
  if(BC1_status == LOW) {
    Page += String(F("<a class='bcon' href='/bc1'>Bancada 01</a>"));
  } else {
    Page += String(F("<a class='bcoff' href='/bc1'>Bancada 01</a>"));
  }
  if(BC2_status == LOW) {
    Page += String(F("<a class='bcon' href='/bc2'>Bancada 02</a>"));
  } else {
    Page += String(F("<a class='bcoff' href='/bc2'>Bancada 02</a>"));
  }
  if(BC3_status == LOW) {
    Page += String(F("<a class='bcon' href='/bc3'>Bancada 03</a>"));
  } else {
    Page += String(F("<a class='bcoff' href='/bc3'>Bancada 03</a>"));
  }
  if(BC4_status == LOW) {
    Page += String(F("<a class='bcon' href='/bc4'>Bancada 04</a>"));
  } else {
    Page += String(F("<a class='bcoff' href='/bc4'>Bancada 04</a>"));
  }
  if(BC5_status == LOW) {
    Page += String(F("<a class='bcon' href='/bc5'>Bancada 05</a>"));
  } else {
    Page += String(F("<a class='bcoff' href='/bc5'>Bancada 05</a>"));
  }
  if(BC6_status == LOW) {
    Page += String(F("<a class='bcon' href='/bc6'>Bancada 06</a>"));
  } else {
    Page += String(F("<a class='bcoff' href='/bc6'>Bancada 06</a>"));
  }
  //-------------------------------------------------
  Page += F("</div>"
            "<div class='coluna-direita'>");
  if(BC7_status == LOW) {
    Page += String(F("<a class='bcon' href='/bc7'>Bancada 07</a>"));
  } else {
    Page += String(F("<a class='bcoff' href='/bc7'>Bancada 07</a>"));
  }
  if(BC8_status == LOW) {
    Page += String(F("<a class='bcon' href='/bc8'>Bancada 08</a>"));
  } else {
    Page += String(F("<a class='bcoff' href='/bc8'>Bancada 08</a>"));
  }
  if(BC9_status == LOW) {
    Page += String(F("<a class='bcon' href='/bc9'>Bancada 09</a>"));
  } else {
    Page += String(F("<a class='bcoff' href='/bc9'>Bancada 09</a>"));
  }
  if(BC10_status == LOW) {
    Page += String(F("<a class='bcon' href='/bc10'>Bancada 10</a>"));
  } else {
    Page += String(F("<a class='bcoff' href='/bc10'>Bancada 10</a>"));
  }
  if(BC11_status == LOW) {
    Page += String(F("<a class='bcon' href='/bc11'>Bancada 11</a>"));
  } else {
    Page += String(F("<a class='bcoff' href='/bc11'>Bancada 11</a>"));
  }
  if(BC12_status == LOW) {
    Page += String(F("<a class='bcon' href='/bc12'>Bancada 12</a>"));
  } else {
    Page += String(F("<a class='bcoff' href='/bc12'>Bancada 12</a>"));
  }
  //-------------------------------------------------
  Page += F("           </div>"
            "        </div>"
            "    </div>"
            "</body>"
            "</html>");
  return indexHTML;
}