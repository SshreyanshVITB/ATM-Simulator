function downloadFile() {

  let account = document.getElementById("account").value;
  let pin = document.getElementById("pin").value;
  let amount = document.getElementById("amount").value;

  let data =
`LOGIN ${account} ${pin}
AMOUNT ${amount}`;

  const blob = new Blob([data], { type: "text/plain" });

  const link = document.createElement("a");
  link.href = URL.createObjectURL(blob);

  link.download = "request.txt";  // IMPORTANT FILE NAME

  link.click();
}